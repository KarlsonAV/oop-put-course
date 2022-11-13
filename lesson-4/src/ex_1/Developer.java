package ex_1;

// Immutable class Developer that implements Employee interface
public final class Developer implements Employee {
    private final String name;
    private final String surname;
    private final Integer age;
    private final String seniority;
    private final String programmingLanguage;

    Developer(String name, String surname, Integer age, String seniority, String programmingLanguage) {
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.seniority = seniority;
        this.programmingLanguage = programmingLanguage;
    }


    @Override
    public void introduceYourself() {
        System.out.printf(
                "\nName and surname - %s %s\nAge - %d\nSeniority - %s\nProgramming Language - %s\n",
                name, surname, age, seniority, programmingLanguage
        );
    }
}
