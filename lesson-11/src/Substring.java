class Substring extends Characters {
    public Substring(Sequence sequence, int start, int end) {
        super(sequence.printedSeq().substring(start, end));
    }
}