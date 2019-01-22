package cn.goktech.study;

public class EnemyBullet extends FlyingObject{
	private int steep=3;
	
	public EnemyBullet(int x,int y) {
		image=MainActivity.enemyBullet;
		height=image.getHeight();
		width=image.getWidth();
		this.pointX=x;
		this.pointY=y;
	}
	@Override
	public void step() {
		// TODO 自动生成的方法存根
		this.pointY+=steep;
	}

	@Override
	public boolean outOfBounds() {
		// TODO 自动生成的方法存根
		return this.pointY>MainActivity.HEIGHT;
	}

}
