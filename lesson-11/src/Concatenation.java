class Concatenation extends Characters {
    public Concatenation(Sequence sequence1, Sequence sequence2) {
        super(sequence1.printedSeq() + sequence2.printedSeq());
    }
}