package cn.goktech.study;

import java.awt.image.BufferedImage;



public class MyAirPlane extends FlyingObject{
	private int life;
	private int doubleFire;
	
	private BufferedImage []images;
	private int index;
	
	
	public MyAirPlane() {
		image=MainActivity.myAirPlane0;
		height=image.getHeight();
		width=image.getWidth();
		pointX=192;
		pointY=550;
		life=3;
		doubleFire=20;
		
		images=new BufferedImage[] {MainActivity.myAirPlane0,MainActivity.myAirPlane1};
		index=0;
		
	}
	
	//实现喷火的效果（图片切换）
	@Override
	public void step() {
		image =images[index++/10%images.length];
	}
	/**
	 * 子弹发射击的方法
	 */
	public Bullet[] shoot(){
		int pointXX=this.width/4;
		int pointYY=this.height/2;
		if(doubleFire>0) {
			Bullet []bullets=new Bullet[2];
			bullets[0]=new Bullet(this.pointX+pointXX, this.pointY+pointYY);
			bullets[1]=new Bullet(this.pointX+3*pointXX, this.pointY+pointYY);
			doubleFire-=2;
			return bullets;
		}else {
			Bullet []bullets=new Bullet[1];
			bullets[0]=new Bullet(this.pointX+2*pointXX, this.pointY);
			return bullets;
		}
	}
	
	@Override
	public boolean outOfBounds() {
		// TODO 自动生成的方法存根
		return false;
	}
	public void addLife() {
		life+=1;
	}
	public int getLife() {
		return this.life;
	}
	public void addDoubleFire() {
		doubleFire+=20;
	}
	public void stractLife() {
		life-=1;
	}
	public void clearDoubleFire() {
		doubleFire=0;
	}
	public boolean hit(FlyingObject obj) {
		int x1=obj.pointX-this.width/2;
		int x2=obj.pointX+obj.width+this.width/2;
		int y1=obj.pointY-this.height/2;
		int y2=obj.pointY+obj.height+this.height/2;
		
		int x=this.pointX+this.width/2;
		int y=this.pointY+this.height/2;
		return (x>x1&&x<x2) && (y>y1 &&y<y2);
	}
	
	/**
	 * 
	 * @param x
	 * @param y
	 */
	public void moveTo(int x,int y) {
		this.pointX=x-this.width/2;
		this.pointY=y-this.height/2;
	}

}
