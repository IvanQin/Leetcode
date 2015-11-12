package veloxcontroller;
import se.imsys.system.*;
public class PortHandler {
	PortIO port;
	final int PORT_C=2;
	final int PORT_NUMBER=8;
	public PortHandler(){
		this.port=new PortIO(PORT_C);
		for (int i=0;i<PORT_NUMBER;i++)
			port.setControlBit(i);
	}
	public void turnOff(int num){
		port.setControlBit(num);
		port.clearDataBit(num);
		
	}
	public void turnOn(int num){
		port.setControlBit(num);
		port.setDataBit(num);
	}
	public String getAllStatus(){
		String s=new String("");
	
		for (int i=0;i<PORT_NUMBER;i++){
			port.clearControlBit(i);
			s=s+port.getDataBit(i);
		}
		s=s+"=Port";
		return s;
	}
	public int getBitStatus(int num){
		port.clearControlBit(num);
		return port.getDataBit(num);
	}
}
