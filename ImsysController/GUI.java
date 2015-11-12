package veloxcontroller;

import javax.swing.JApplet;
import java.util.Date;
import javax.swing.border.TitledBorder;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.Vector;

import javax.swing.*;

public class GUI extends JApplet{
	
	Container con;
	JPanel basicInfo;
	JPanel portStatus;
	JPanel console;
	JPanel action;
	JLabel RTCTime;
	JLabel RTCTime_d;
	JLabel Cal;
	JLabel Cal_d;
	JLabel[] PC;
	JLabel[] PC_d;
	JTextArea com;
	JScrollPane command;
	JLabel turnOn;
	JLabel turnOff;
	JComboBox<String> onPort;
	JComboBox<String> offPort;
	Vector <String> port;
	JButton reset;
	JButton confirm;
	
	int reset_s;
	int getTime_s;
	int turnOn_s;
	int turnOff_s;
	final int PORT_NUMBER=8;
	final int FRESH_FREQ=1000;
	
	final String localhost="http://192.168.1.101/cgi-bin/simple.cgi";
	public void init(){
		Font titleFont=new Font("Courier",Font.BOLD,15);
		this.setName("Velox Controller");
		this.setSize(600, 1000);
		con=this.getContentPane();
		con.setLayout(new GridLayout(4,1));
		
		basicInfo=new JPanel();
		basicInfo.setBorder(BorderFactory.createTitledBorder(null, "Basic Information", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, titleFont));
		basicInfo.setLayout(new GridLayout(1,2));
		RTCTime=new JLabel("RTC Time");
		RTCTime_d=new JLabel();
		Cal=new JLabel("System Time");
		Cal_d=new JLabel ();
		basicInfo.add(RTCTime);
		basicInfo.add(RTCTime_d);
		basicInfo.add(Cal);
		basicInfo.add(Cal_d);
		
		
		portStatus=new JPanel();
		portStatus.setBorder(BorderFactory.createTitledBorder(null, "Port Status", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, titleFont));
		portStatus.setLayout(new GridLayout(4,4));
		PC=new JLabel[PORT_NUMBER];
		PC_d=new JLabel[PORT_NUMBER];
		for (int i=0;i<PORT_NUMBER;i++){
			PC[i]=new JLabel("PC_"+i);
			PC_d[i]=new JLabel();
			portStatus.add(PC[i]);
			portStatus.add(PC_d[i]);
		}
	
		action=new JPanel();
		action.setBorder(BorderFactory.createTitledBorder(null, "Action", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, titleFont));
		action.setLayout(new GridLayout(3,2));
		turnOn=new JLabel("Turn On");
		turnOff=new JLabel("Turn Off");
		port=new Vector<String>();
		port.addElement("none");
		for (int i=0;i<8;i++)
			port.addElement(""+i);
		onPort=new JComboBox<String> (port);
		offPort=new JComboBox<String> (port);
		reset=new JButton("Reset");
		confirm=new JButton("confirm");
		reset.addActionListener(new ResetAction());
		confirm.addActionListener(new ConfirmAction());
		action.add(turnOn);
		action.add(onPort);
		action.add(turnOff);
		action.add(offPort);
		action.add(reset);
		action.add(confirm);	
		
		console=new JPanel();
		console.setBorder(BorderFactory.createTitledBorder(null, "Console", TitledBorder.DEFAULT_JUSTIFICATION, TitledBorder.DEFAULT_POSITION, titleFont));
		com=new JTextArea(7,30);
		com.setLineWrap(true);
		com.setWrapStyleWord(true);
		command=new JScrollPane(com);
		command.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		command.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		console.add(command);
		
		con.add(basicInfo);
		con.add(portStatus);
		con.add(action);
		con.add(console);
		
		reset_s=1;
		getTime_s=1;
		turnOn_s=-1;
		turnOff_s=-1;
		
		Thread thread=new Thread(new TimeHandler());
		thread.start();
		
		//go();
		}
	public void go(){
		request();
		
	}
	public void request(){
		URL url=getURL(getReq());
		System.out.println(url.toString());
		try{	
			InputStream response=url.openStream();
			InputStreamReader streamReader=new InputStreamReader(response);
			BufferedReader reader=new BufferedReader(streamReader);
			display(reader);
			
		}catch (Exception e){
			System.out.println(url.toString());
			e.printStackTrace();
		}
		
	}
	public void display(BufferedReader reader){
		String s;
		System.out.println("Going to display!");
		try{
			do{
				s=reader.readLine();
				System.out.println(s);
				if (s==null) break;
				if (s.endsWith("=RTCTime")){
					RTCTime_d.setText(fetch(s));
				}
				else if (s.endsWith("=Port")){
					for (int i=0;i<PORT_NUMBER;i++){
						int sat=(int) (s.charAt(i)-'0');
						PC_d[i].setText(""+sat);
					}
				}
				else if (s.endsWith("=turnOn")){
					String tmp=new String("LED ");
					if (!(fetch(s).equals("!")))
						tmp=tmp+fetch(s)+" has been turned on successfully!"+"\n";
					else tmp="Failed to turn on the LED!"+"\n";
					com.append(tmp);
				}
				else if (s.endsWith("=turnOff")){
					String tmp=new String("LED ");
					if (!(fetch(s).equals("!")))
						tmp=tmp+fetch(s)+" has been turned off successfully!"+"\n";
					else tmp="Failed to turn off the LED!"+"\n";
					com.append(tmp);
				}
				else if (s.endsWith("=reset")){
					com.append("Successfully reset!"+"\n");
				}
			}while (true);
		}catch (Exception e){
			e.printStackTrace();
		}	
	}
	public String fetch (String s){
		return s.substring(0, findEqual(s));
	}
	int findEqual (String s){
		int i=0;
		while (s.charAt(i)!='\n'){
			System.out.println(s.charAt(i));
			if (s.charAt(i)=='='){
				break;
			}
			i++;
		}
		return i-1;	
	}
	public String getReq(){
		String req=new String();
		req="reset="+reset_s+"&";
		req=req+"getTime="+getTime_s+"&";
		req=req+"turnOn="+turnOn_s+"&";
		req=req+"turnOff="+turnOff_s;
		return req;
	}
	public URL getURL(String req){
		String str=new String();
		str=""+localhost+"?"+req;
		URL url = null;
		try{
			url=new URL(str);
		}catch (Exception e){
			e.printStackTrace();
		}
		return url;
	}
	
	public class ResetAction implements ActionListener{

		public void actionPerformed(ActionEvent e) {
			com.append("Doing reset..."+"\n");
			reset_s=1;
			getTime_s=1;
			turnOn_s=-1;
			turnOff_s=PORT_NUMBER;
			go();
		}
		
	}
	public class ConfirmAction implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			com.append("Doing confirm..."+"\n");
			reset_s=0;
			getTime_s=1;
			String tmp=(String) onPort.getSelectedItem();
			if ("none".equals(tmp))
				turnOn_s=-1;
			else turnOn_s=Integer.parseInt(tmp);
			tmp=(String) offPort.getSelectedItem();
			if ("none".equals(tmp))
				turnOff_s=-1;
			else turnOff_s=Integer.parseInt(tmp);
			go();
		}
		
	}
	
	public class TimeHandler implements Runnable{
		public void run() {
			while (true){
				try{
					Thread.sleep(FRESH_FREQ);
				}catch (Exception e){
					e.printStackTrace();
				}
			    Date date=new Date();
				Cal_d.setText(date.toString());
			}
		}
	}
	

}
	
