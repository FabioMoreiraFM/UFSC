package projeto;

public class Ocorrencia {

	private String descricaoOcorrencia;
	private TipoOcorrencia tarefa;
	private Status status;
	private Funcionario responsavel;
	private Prioridade prioridade;
	private static Integer chavePrincipal = 0;
	private Integer chaveOcorrencia;

	public Ocorrencia(String ocorrencia, TipoOcorrencia bug, Status aberta, Funcionario responsavel, Prioridade alta) {
		this.descricaoOcorrencia = ocorrencia;
		this.tarefa = bug;
		this.status = aberta;
		this.responsavel = responsavel;
		this.prioridade = alta;
		this.chaveOcorrencia = chavePrincipal;
		chavePrincipal++;		
	}
	
	public Integer getChave() {
		return chaveOcorrencia;
	}
	
	public String getDescricaoOcorrencia() {
		return descricaoOcorrencia;
	}

	public TipoOcorrencia getTarefa() {
		return tarefa;
	}

	public Status getStatus() {
		return status;
	}

	public Funcionario getResponsavel() {
		return responsavel;
	}

	public void setPrioridade(Prioridade novaPrioridade) throws Exception {
		if (status == Status.Aberta) {
			this.prioridade = novaPrioridade;		
		} else {
			throw new Exception();
		}
	}

	public Prioridade getPrioridade() {
		return prioridade;
	}

	public void setStatus(Status novoStatus) {
		this.status = novoStatus;
	}

	public void setResponsavel(Funcionario novoResponsavel) throws Exception {
		if (status == Status.Aberta) {
			this.responsavel = novoResponsavel;
		} else {
			throw new Exception();
		}
	}
}
