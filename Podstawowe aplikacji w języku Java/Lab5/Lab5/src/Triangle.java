import java.awt.*;

public class Triangle extends Polygon{
    private double height;
    private double base;
    public Triangle(Color color, int perimeter, double height, double base) {
        super(color, 0, perimeter, 3, 3, 180);
        this.height = height;
        this.base = base;
        countArea();
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

    @Override
    public int getVerticesCount() {
        return super.getVerticesCount();
    }

    @Override
    public void setVerticesCount(int verticesCount) {
        super.setVerticesCount(verticesCount);
    }

    @Override
    public int getSidesCount() {
        return super.getSidesCount();
    }

    @Override
    public void setSidesCount(int sidesCount) {
        super.setSidesCount(sidesCount);
    }

    @Override
    public double getAngleSum() {
        return super.getAngleSum();
    }

    @Override
    public void setAngleSum(double angleSum) {
        super.setAngleSum(angleSum);
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public void countArea(){
        super.setArea(0.5 * height * base);
    }

}
