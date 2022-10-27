package ex_2;

public class FaceWash {

    private String productName;
    private double _price;
    private double _volume;

    FaceWash() {
        this("", 0.0, 0.0);
    }


    FaceWash(String name, Integer price) {
        this(name, Double.valueOf(price), 0.0);
    }

    FaceWash(String name, double price, Integer volume) {
        this.productName = name;
        this._price = price;
        this._volume = Double.valueOf(volume);
    }

    FaceWash(String name, double price, double volume) {
        this.productName = name;
        this._price = price;
        this._volume = volume;
    }


    public void showInfo() {
        System.out.println("Product Name - " + productName + ", Price - " + _price);
    }

    public double doublePrice() {
        return _price;
    }

    public int intPrice() {
        return (int) _price;
    }

    public double doubleVolume() {
        return _volume;
    }

    public int intVolume() {
        return (int) _volume;
    }

}
