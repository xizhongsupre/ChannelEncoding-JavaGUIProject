package cn.goktech.study;

import java.util.Random;

/**
 * 敌机类型二：
 * 特点：机型中，速度较快，生成位置以及方向随机，击中可以加生命值
 * 额外想完成的要求：需要我们击中其很多次才会消失
 * @author ASUS
 *
 */
public class EnemyTypeTwo extends FlyingObject implements BeatenEnemyAward{
	public int xSteep=2;
	public int ySteep=2;
	Random random=new Random();
	public EnemyTypeTwo() {
		image=MainActivity.enemyTypeTwo;
		height=image.getHeight();
		width=image.getWidth();
		pointX=random.nextInt(MainActivity.WIDTH-this.width);
		pointY=random.nextInt((MainActivity.HEIGHT+this.height)/2);
	}
	@Override
	public void step() {
		this.pointX+=xSteep;
		this.pointY+=ySteep;
		if(this.pointX>MainActivity.WIDTH-this.width) {
			xSteep=-2;ySteep=random.nextInt(5);
		}
		if(this.pointX<0) {
			xSteep=2;ySteep=random.nextInt(3);
		}
		
	}

	@Override
	public boolean getLife() {
		// TODO 自动生成的方法存根
		return true;
	}

	@Override
	public int getScore() {
		return 0;
	}
	
	@Override
	public boolean getDouobleFire() {
		return false;
	}

	@Override
	public boolean outOfBounds() {
		return this.pointY>MainActivity.HEIGHT;
	}

}
