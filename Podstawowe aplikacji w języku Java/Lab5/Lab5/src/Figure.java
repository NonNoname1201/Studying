import java.awt.*;

public class Figure {
    private Color color;
    protected double area;
    protected double perimeter;

    public Figure(Color color, double area, double perimeter) {
        this.color = color;
        this.area = area;
        this.perimeter = perimeter;
    }

    public Figure() {
    }

    protected void draw(){}
    protected void delete(){}
    protected void move(){}
    protected String giveParameters(){
        return null;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double getPerimeter() {
        return perimeter;
    }

    public void setPerimeter(double perimeter) {
        this.perimeter = perimeter;
    }

}
