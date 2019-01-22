package cn.goktech.study;

import java.awt.image.BufferedImage;

public abstract class FlyingObject {
	public BufferedImage image;
	public int height,width;
	public int pointX,pointY;
	
	public abstract void step();
	
	public abstract boolean outOfBounds();
	
	public boolean shootBy(Bullet bullet) {
		//确定飞行物边界
		int xBoundary1=this.pointX;
		int xBoundary2=this.pointX+this.width;
		int yBoundary1=this.pointY;
		int yBoundary2=this.pointY+this.height;
		
		return (bullet.pointX>xBoundary1 && bullet.pointX<xBoundary2 )&&( bullet.pointY>yBoundary1 && bullet.pointY<yBoundary2) ;
			
		
		
	}

}
