package ex_1;

public class Television {
    private String company;
    private Double screenSize;
    private String resolution;


    Television() {
        this("", 0.0, "");
    }

    Television(String company) {
        this(company, 0.0, "");
    }

    Television(String company, Double screenSize) {
        this(company, screenSize, "");
    }

    Television(String company, Integer screenSize) {
        this(company, Double.valueOf(screenSize));
    }


    Television(String company, Integer screenSize, String resolution) {
        this(company, Double.valueOf(screenSize), resolution);
    }

    Television(String company, Double screenSize, String resolution) {

        this.company = company;
        this.screenSize = screenSize;
        this.resolution = resolution;

    }

    public void showSpecs() {
        System.out.println("Company - " + company + ", Screen Size - " + screenSize + ", Resolution - " + resolution);
    }

}
