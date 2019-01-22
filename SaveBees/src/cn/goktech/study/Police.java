/**
 * 写在前面，本来这个监听器是想用按键来控制子弹发射的，因为某些原因搁置了
 */
package cn.goktech.study;
/**
 * 我尝试给子弹发射加上监听器，也不知道能不能实现
 * 
 */
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Police implements KeyListener,FocusListener{

	@Override
	public void focusGained(FocusEvent e) {
		// TODO 自动生成的方法存根
		
	}

	@Override
	public void focusLost(FocusEvent e) {
		// TODO 自动生成的方法存根
		
	}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO 自动生成的方法存根
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode()==KeyEvent.VK_SPACE) {
			MainActivity test=new MainActivity();
			test.bullets[test.bullets.length-1].step();
		}
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO 自动生成的方法存根
		
	}
	

}
