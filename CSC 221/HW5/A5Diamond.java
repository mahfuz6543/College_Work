package edu.cuny.ccny.a5.shape;

public class A5Diamond {
    private double x;
    private double y;
    private double radius;

    public A5Diamond(){this(0.0, 0.0, 0.0);}
    public A5Diamond(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
}

