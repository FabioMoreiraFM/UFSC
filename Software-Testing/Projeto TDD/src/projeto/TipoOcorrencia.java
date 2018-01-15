package projeto;

public enum TipoOcorrencia {
    Melhoria(0), Bug(1), Tarefa(2);

    public int tipoOcorrencia;
    TipoOcorrencia(int valor) {
    	tipoOcorrencia = valor;
    }
}
