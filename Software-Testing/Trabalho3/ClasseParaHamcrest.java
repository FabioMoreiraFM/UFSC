package testes;

public class ClasseParaHamcrest {

	private Integer inteiro;
	private String nome;
	private Integer[] array;
	
	public ClasseParaHamcrest(Integer inteiro, String nome, Integer um, Integer dois) {
		this.inteiro = inteiro;
		this.nome = nome;
		array = new Integer[2];
		array[0] = um;
		array[1] = dois;
	}

	public Integer getInteiro() {
		return inteiro;
	}

	public String getString() {
		return nome;
	}
	
	public Integer[] getArray(){
		return array;
	}
}
