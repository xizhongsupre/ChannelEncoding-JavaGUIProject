package cn.goktech.study;

import java.util.Random;

/**
 * 这是第三种敌机：
 * 特点：最大，速度较快，方向随机，奖励机制为加火力
 * 额外目标：可以发射火力
 *
 * @author ASUS
 *
 */
public class EnemyTypeThree extends FlyingObject implements BeatenEnemyAward{
	public int xSteep=2;
	public int ySteep=2;
	
	public EnemyTypeThree() {
		image=MainActivity.enemyTypeThree;
		height=image.getHeight();
		width=image.getWidth();
		Random random=new Random();
		pointX=random.nextInt(MainActivity.WIDTH-this.width);
		pointY=-this.height;
	}
	
	@Override
	public void step() {
		this.pointY+=ySteep;
	}
	

	@Override
	public boolean getDouobleFire() {
		// TODO 自动生成的方法存根
		return true;
	}

	@Override
	public int getScore() {
		// TODO 自动生成的方法存根
		return 0;
	}

	@Override
	public boolean getLife() {
		// TODO 自动生成的方法存根
		return false;
	}
	
	@Override
	public boolean outOfBounds() {
		return this.pointY>MainActivity.HEIGHT;
	}

	public EnemyBullet[] shoot(){
		EnemyBullet []enemyBullets=new EnemyBullet[1];
		enemyBullets[0]=new EnemyBullet(this.pointX+this.width/2-20, this.pointY+this.height);
		return enemyBullets;
	}
}
