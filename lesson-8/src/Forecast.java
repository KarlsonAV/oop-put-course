public interface Forecast {
    float todayTemperature();
    final class Fake implements Forecast {
        @Override
        public float todayTemperature() {
            return 12.05f;
        }
    }

}
