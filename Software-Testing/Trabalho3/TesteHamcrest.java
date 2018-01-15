package testes;

import static org.hamcrest.MatcherAssert.*;
import static org.hamcrest.core.IsEqual.*;
import static org.hamcrest.core.AllOf.*;
import static org.hamcrest.core.AnyOf.*;
import static org.hamcrest.Matchers.greaterThan;
import static org.hamcrest.Matchers.lessThanOrEqualTo;
import static org.hamcrest.Matchers.not;
import org.junit.*;


public class TesteHamcrest {
	private ClasseParaHamcrest cph;
	
	@Before
	public void setupClasseTeste() {
		cph = new ClasseParaHamcrest(1,"Oi", 2,3);
	}
	
	@Test
	public void ObjetosIguais(){
		ClasseParaHamcrest cph2 = new ClasseParaHamcrest(1,"Oi", 2,3);
		assertThat(cph, not(equalTo(cph2)));
	}
	
	@Test
	public void TextMatcher() {
		assertThat("Oi", equalTo(cph.getString()));
	}
	
	@Test
	public void numberMatcher() {
		assertThat(1, equalTo(cph.getInteiro()));
	}
	
	@Test
	public void arrayMatcher() {
		Integer[] array = cph.getArray(); 
		assertThat(2, equalTo(array[0]));
		assertThat(3, equalTo(array[1]));
	}
	
	@Test
	public void allAnyOf() {
		assertThat(2, allOf(greaterThan(cph.getInteiro()),lessThanOrEqualTo(cph.getInteiro()+5)));
		assertThat(1, anyOf(greaterThan(cph.getInteiro()),lessThanOrEqualTo(cph.getInteiro()+5)));
	}	
	
}
