package cn.goktech.study;

import java.util.Random;

/**
 * 代表邪恶势力飞机1
 * 特点：较小，，速度不快，方向向下，击中奖励为加分
 * @author ASUS
 *
 */
public class EnemyTypeOne extends FlyingObject implements BeatenEnemyAward{
	public int steep=2;
	
//	写个构造方法设定我们飞行物出场的位置坐标
	public EnemyTypeOne() {
		image=MainActivity.enemyTypeOne;
		height=image.getHeight();
		width=image.getWidth();
		Random random=new Random();
		pointX=random.nextInt(MainActivity.WIDTH-this.width);
		pointY=-this.height;
		
	}
	@Override
	public void step() {
		this.pointY+=steep;
		
	}

	@Override
	public int getScore() {
		// TODO 自动生成的方法存根
		return 5;
	}

	@Override
	public boolean getLife() {
		// TODO 自动生成的方法存根
		return false;
	}

	@Override
	public boolean getDouobleFire() {
		// TODO 自动生成的方法存根
		return false;
	}
	@Override
	public boolean outOfBounds() {
		return this.pointY>MainActivity.HEIGHT;
	}

}
