package projeto;

public enum Status {
    Aberta(0),Fechada(1);

    public int status;
    Status(int valor) {
        status = valor;
    }
}
