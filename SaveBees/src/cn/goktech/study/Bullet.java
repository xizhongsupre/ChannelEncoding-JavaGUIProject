package cn.goktech.study;
/**
 * 这是子弹
 * 特点：速度较慢,方向向上，可以由我们通过键盘自己控制
 * 额外想达到的目标：能够在某一节点达到可以增加火力速度的要求
 * @author ASUS
 *
 */
public class Bullet extends FlyingObject {
	public int steep=2;
	public Bullet(int pointX,int pointY) {
		image=MainActivity.bullet;
		height=image.getHeight();
		width=image.getWidth();
		this.pointX=pointX;
		this.pointY=pointY;
	
	}
	@Override
	public void step() {
		this.pointY-=steep;
		
	}
	@Override
	public boolean outOfBounds() {
		// TODO 自动生成的方法存根
		return this.pointY<-this.height;
	}

}
