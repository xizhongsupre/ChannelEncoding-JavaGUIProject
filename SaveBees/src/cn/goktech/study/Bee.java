package cn.goktech.study;

import java.util.Random;

/**
 * 这是我们需要拯救的蜜蜂
 * 特点：
 * 飞行速度较慢，飞行方向随机，我们如果不幸击中小蜜蜂的话我们就会失去一条命
 * @author ASUS
 *
 */
public class Bee extends FlyingObject implements SorryForBee{
	public int xSteep=2;
	public int ySteep=2;
	public Bee() {
		image=MainActivity.bee;
		height=image.getHeight();
		width=image.getWidth();
		Random random=new Random();
		pointX=random.nextInt(MainActivity.WIDTH-this.width);
		pointY=this.height;
	}
	
	@Override
	public void step() {
		this.pointX+=xSteep;
		this.pointY+=ySteep;
		if(this.pointX>MainActivity.WIDTH-this.width) {
			xSteep=-2;
		}
		if(this.pointX<0) {
			xSteep=2;
		}
		
		
	}
	
	@Override
	public boolean isErrorKill() {
		// TODO 自动生成的方法存根
		return true;
	}
	
	@Override
	public boolean outOfBounds() {
		return this.pointY>MainActivity.HEIGHT;
	}


}
