import java.awt.*;

class Polygon extends Figure{
    private int verticesCount;
    private int sidesCount;
    private double angleSum;

    public Polygon(Color color, int area, int perimeter,
                   int verticesCount, int sidesCount, double angleSum) {
        super(color, area, perimeter);
        this.verticesCount = verticesCount;
        this.sidesCount = sidesCount;
        this.angleSum = angleSum;
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

    public int getVerticesCount() {
        return verticesCount;
    }

    public void setVerticesCount(int verticesCount) {
        this.verticesCount = verticesCount;
    }

    public int getSidesCount() {
        return sidesCount;
    }

    public void setSidesCount(int sidesCount) {
        this.sidesCount = sidesCount;
    }

    public double getAngleSum() {
        return angleSum;
    }

    public void setAngleSum(double angleSum) {
        this.angleSum = angleSum;
    }

    private void countAngleSum(){
        this.angleSum = (sidesCount - 2) * 180;
    }
}
