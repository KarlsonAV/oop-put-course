public class Characters implements Sequence {
    private String sequence;

    public Characters(String sequence) {
        this.sequence = sequence;
    }

    @Override
    public String printedSeq() {
        return sequence;
    }
}
