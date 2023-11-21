package lmi;

class Test<T> {
    Class<T> getMyType() {
        return (Class<T>)this.getClass();
    }
}
