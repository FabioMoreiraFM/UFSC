package projeto;

import java.util.ArrayList;
import java.util.List;

public class Projeto {

	private String nomeProjeto;
	private List<Ocorrencia> ocorrencias;
	private List<Funcionario> funcionarios;
	
	public Projeto(String nomeProjeto) {
		this.nomeProjeto = nomeProjeto;
		ocorrencias = new ArrayList<Ocorrencia>();
		funcionarios = new ArrayList<Funcionario>();
	}

	public String getNomeProjeto() {
		return nomeProjeto;
	}

	public void addOcorrencia(Ocorrencia ocorrencia) {
		ocorrencias.add(ocorrencia);
	}

	public Ocorrencia getOcorrencia(int index) {
		return ocorrencias.get(index);
	}

	public void addFuncionarioAoProjeto(Funcionario umFuncionario) {
		funcionarios.add(umFuncionario);
	}

	public Funcionario getFuncionario(int index) {
		return funcionarios.get(index);
	}

	public void addOcorrenciaAFuncionario(Integer funcionarioEscolhidoParaResolver, Integer ocorrenciaAberta) throws Exception {
		funcionarios.get(funcionarioEscolhidoParaResolver).addOcorrencia(ocorrencias.get(ocorrenciaAberta));		
	}

}
