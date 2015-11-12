package veloxcontroller;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.Hashtable;   
import se.imsys.net.*;
public class SimpleCGI implements HttpCgi {
	RTCtime t;
	PortHandler portHandler;
	public SimpleCGI(){
		
          }

	public String getName(){
		return("simple.cgi");
	}

	public void execute(Hashtable variables, OutputStream out) throws IOException{
		int i;
		String s;
		Enumeration keys;
		String key;
		
		t=new RTCtime();
		portHandler=new PortHandler();
		s = "Content-Type: text/html\r\n\r\n\r\n";
		out.write(s.getBytes());

		keys = variables.keys();
		while (keys.hasMoreElements()) {
			int num;
			key = (String)keys.nextElement();
			String man=variables.get(key).toString();
			System.out.println("Get from client : key="+key+" value="+man);
			/*switch (key){
				case "getTime":
					if ("1".equals(man)){
						s=""+t.getTime()+"=RTCTime"+"\n";
						out.write(s.getBytes());
					}
					break;
				case "turnOn":
					if ("-1".equals(man)) break;
					num=Integer.parseInt(man);
					portHandler.turnOn(num);
					s=portHandler.getAllStatus()+"=Port\n";
					out.write(s.getBytes());
					break;
				case "turnOff":
					if ("-1".equals(man)) break;
					num=Integer.parseInt(man);
					portHandler.turnOff(num);
					s=portHandler.getAllStatus()+"=Port\n";
					out.write(s.getBytes());
					break;
				case "reset":
					if ("1".equals(man)){
						for (i=0;i<7;i++)
							portHandler.turnOff(i);
						s=portHandler.getAllStatus()+"=Port\n";
						out.write(s.getBytes());
					}
					break;
			default:
			}*/
			if ("getTime".equals(key)){
				
				if ("1".equals(man)){
					s=""+t.getTime()+"=RTCTime"+"\n";
					out.write(s.getBytes());
				}
				
			}
			else if ("turnOn".equals(key)){
				
				if (!("-1".equals(man))){
					num=Integer.parseInt(man);
					portHandler.turnOn(num);
					if (portHandler.getBitStatus(num)==1)
						s=""+num+"=turnOn"+"\n";
					else s="!"+"=turnOn"+"\n";
					out.write(s.getBytes());
					s=portHandler.getAllStatus()+"=Port\n";
					out.write(s.getBytes());
				}
				
			}
			else if ("turnOff".equals(key)){
				
				if (!("-1".equals(man))){
					num=Integer.parseInt(man);
					portHandler.turnOff(num);
					if (portHandler.getBitStatus(num)==0)
						s=""+num+"=turnOff"+"\n";
					else s="!"+"=turnOff"+"\n";
					out.write(s.getBytes());
					s=portHandler.getAllStatus()+"=Port\n";
					out.write(s.getBytes());
				}
			}
			else if ("reset".equals(key)){
				if ("1".equals(man)){
					for (i=0;i<7;i++)
						portHandler.turnOff(i);
					s="=reset"+"\n";
					out.write(s.getBytes());
					s=portHandler.getAllStatus()+"=Port\n";
					out.write(s.getBytes());
				}
				
			}
			System.out.println(s);
		}
						
	}
}

 