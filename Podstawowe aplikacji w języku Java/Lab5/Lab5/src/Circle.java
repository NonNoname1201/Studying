import java.awt.*;

public class Circle extends Ellipse{
    public Circle(Color color, double radius, Point centre) {
        super(color, 0, 0, radius, radius, centre, centre);
        countArea();
        countPerimeter();
    }
    @Override
    public double getSmallRadius() {
        return super.getSmallRadius();
    }

    @Override
    public void setSmallRadius(double smallRadius) {
        super.setSmallRadius(smallRadius);
    }

    @Override
    public double getLargeRadius() {
        return super.getLargeRadius();
    }

    @Override
    public void setLargeRadius(double largeRadius) {
        super.setLargeRadius(largeRadius);
    }

    @Override
    public Point getF1() {
        return super.getF1();
    }

    @Override
    public void setF1(Point f1) {
        super.setF1(f1);
    }

    @Override
    public Point getF2() {
        return super.getF2();
    }

    @Override
    public void setF2(Point f2) {
        super.setF2(f2);
    }

    @Override
    public double getFocalDelta() {
        return super.getFocalDelta();
    }

    @Override
    protected void draw() {
        super.draw();
    }

    @Override
    protected void delete() {
        super.delete();
    }

    @Override
    protected void move() {
        super.move();
    }

    @Override
    protected String giveParameters() {
        return super.giveParameters();
    }

    @Override
    public Color getColor() {
        return super.getColor();
    }

    @Override
    public void setColor(Color color) {
        super.setColor(color);
    }

    @Override
    public double getArea() {
        return super.getArea();
    }

    @Override
    public void setArea(double area) {
        super.setArea(area);
    }

    @Override
    public double getPerimeter() {
        return super.getPerimeter();
    }

    @Override
    public void setPerimeter(double perimeter) {
        super.setPerimeter(perimeter);
    }

    public void countArea(){
        setArea(Math.pow(getLargeRadius(), 2) * Math.PI);
    }
    public void countPerimeter(){
        setPerimeter(getLargeRadius() * Math.PI * 2);
    }
}