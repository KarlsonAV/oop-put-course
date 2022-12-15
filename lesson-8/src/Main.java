public class Main {
    public static void main(String[] args) {
        Forecast forecast = new Forecast.Fake();
        Weather yesterday = new Weather(forecast, "C", 10);
        Weather today = yesterday.forecastedWeather("C");
        assert "12.05C".equals(today.toString());
    }
}