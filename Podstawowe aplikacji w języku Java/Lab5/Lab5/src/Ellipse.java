import java.awt.*;

class Ellipse extends Figure {
    private double smallRadius;
    private double largeRadius;
    private Point F1;
    private Point F2;
    private double focalDelta;

    public double getSmallRadius() {
        return smallRadius;
    }

    public void setSmallRadius(double smallRadius) {
        this.smallRadius = smallRadius;
    }

    public double getLargeRadius() {
        return largeRadius;
    }

    public void setLargeRadius(double largeRadius) {
        this.largeRadius = largeRadius;
    }

    public Point getF1() {
        return F1;
    }

    public void setF1(Point f1) {
        F1 = f1;
    }

    public Point getF2() {
        return F2;
    }

    public void setF2(Point f2) {
        F2 = f2;
    }

    public double getFocalDelta() {
        return focalDelta;
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

    public Ellipse(Color color, double area, double perimeter, double smallRadius,
                   double largeRadius, Point f1, Point f2) {
        super(color, area, perimeter);
        this.smallRadius = smallRadius;
        this.largeRadius = largeRadius;
        F1 = f1;
        F2 = f2;
    }

    private void countFocalDelta(){
        this.focalDelta = Math.sqrt(Math.pow(F1.x - F2.x, 2) + Math.pow(F1.y - F2.y, 2))/2;
    }

}