package testes;

import static org.junit.Assert.*;

import org.junit.*;

import br.ufsc.ine.leb.sistemaBancario.Dinheiro;
import br.ufsc.ine.leb.sistemaBancario.Moeda;

public class TesteDinheiro {
	private Dinheiro dezReais;
	
	@Before
	public void setupDinheiro() {
		dezReais = new Dinheiro(Moeda.BRL, 10, 0);
	}
	
	@Test
	public void testarDezReais() {
		assertEquals(Moeda.BRL, dezReais.obterMoeda());
	}
}
