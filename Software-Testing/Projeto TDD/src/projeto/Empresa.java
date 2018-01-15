package projeto;

import java.util.ArrayList;
import java.util.List;

public class Empresa {

	private String nomeEmpresa;
	private List<Funcionario> funcionarios;
	private List<Projeto> projetos;
	
	public Empresa(String nomeEmpresa) {
		this.nomeEmpresa = nomeEmpresa;
		funcionarios = new ArrayList<Funcionario>();
		projetos = new ArrayList<Projeto>();
	}

	public String getNomeEmpresa() {
		return nomeEmpresa;
	}

	public Integer getQtdFuncionarios() {
		return funcionarios.size();
	}

	public void addFuncionario(Funcionario funcionario) {
		funcionarios.add(funcionario);
	}

	public Funcionario getFuncionarios(Integer index) {
		return funcionarios.get(index);
	}

	public void addProjeto(Projeto projeto) {
		projetos.add(projeto);
	}

	public Projeto getProjeto(int index) {
		return projetos.get(index);
	}

	public Integer getQtdProjetos() {
		return projetos.size();
	}

	public void addFuncionarioAoProjeto(Integer funcionario, Integer projeto) {
		projetos.get(projeto).addFuncionarioAoProjeto(funcionarios.get(0));
	}

}
