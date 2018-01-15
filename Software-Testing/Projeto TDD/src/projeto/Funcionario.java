package projeto;

import java.util.ArrayList;
import java.util.List;

public class Funcionario {

	private String nome;
	private List<Ocorrencia> ocorrenciasAbertas;

	public Funcionario(String nome) {
		this.nome = nome;
		this.ocorrenciasAbertas = new ArrayList<Ocorrencia>();
	}

	public String getNome() {
		return nome;
	}

	public void addOcorrencia(Ocorrencia umaOcorrencia) throws Exception {
		if (ocorrenciasAbertas.size() < 10) {
			ocorrenciasAbertas.add(umaOcorrencia);
		} else {
			throw new Exception();
		}
	}

	public Ocorrencia getOcorrencias(int index) {
		return ocorrenciasAbertas.get(index);
	}

}
