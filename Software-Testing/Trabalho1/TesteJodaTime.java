import static org.junit.Assert.*;

import org.joda.time.LocalDate;
import org.joda.time.LocalDateTime;
import org.joda.time.Period;
import org.joda.time.DateTime;
import org.joda.time.Hours;
import org.joda.time.IllegalFieldValueException;
import org.joda.time.Interval;
import org.junit.Test;

public class TesteJodaTime {
	
	@Test
	public void teste1_criarData() {
		// Fixture Setup
		
		// Exercise SUT
		LocalDate novaData = new LocalDate(2017,5,10);
		
		// Result Verification
		assertEquals(2017,novaData.getYear());
		assertEquals(5, novaData.getMonthOfYear());
		assertEquals(10, novaData.getDayOfMonth());		
	}

	@Test(expected = IllegalFieldValueException.class)
	public void teste1_criarDataErrada() {
		// Fixture Setup
		
		// Exercise SUT
		LocalDate novaData = new LocalDate(2017,15,1);
		
		// Result Verification
	}
	
	@Test
	public void teste2_addDatas(){
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,15);
		LocalDate data2 = new LocalDate(2017,5,20);
		
		// Exercise SUT
		data1 = data1.plusDays(5);
		
		// Result Verification
		assertEquals(data2,data1);
	}

	@Test
	public void teste2_addDatasMaior30(){
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,16);
		LocalDate data2 = new LocalDate(2017,6,1);
		
		// Exercise SUT
		data1 = data1.plusDays(16);
		
		// Result Verification
		assertEquals(data2,data1);
	}
	
	@Test
	public void teste3_subtraiDatas(){
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,20);
		LocalDate data2 = new LocalDate(2017,5,15);
		
		// Exercise SUT
		data1 = data1.minusDays(5);
		
		// Result Verification
		assertEquals(data2,data1);
	}
	
	@Test
	public void teste3_subtraiDatasParaVoltarOMes(){
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,1);
		LocalDate data2 = new LocalDate(2017,4,30);
		
		// Exercise SUT
		data1 = data1.minusDays(1);
		
		// Result Verification
		assertEquals(data2,data1);
	}
	
	@Test
	public void teste4_criarHoras() {
		// Fixture Setup
		
		// Exercise SUT
		Hours novahora = Hours.hours(3);
				
		// Result Verification
		assertEquals(3,novahora.getHours());
	}
	
	@Test
	public void teste4_criarHorasNegativas() {
		// Fixture Setup
		
		// Exercise SUT
		Hours novahora = Hours.hours(-5);
				
		// Result Verification
		assertEquals(-5,novahora.getHours());
	}
	
	@Test
	public void teste5_somaHoras() {
		// Fixture Setup
		Hours novahora = Hours.hours(3);
		Hours horamenor = Hours.hours(5);
		
		// Exercise SUT
		novahora = novahora.plus(2);
		
		// Result Verification
		assertEquals(horamenor,novahora);
	}

	@Test
	public void teste5_somaHorasNegativas() {
		// Fixture Setup
		Hours novahora = Hours.hours(-3);
		Hours horamenor = Hours.hours(-1);
		
		// Exercise SUT
		novahora = novahora.plus(2);
		
		// Result Verification
		assertEquals(horamenor,novahora);
	}
	
	@Test
	public void teste6_subtraiHoras() {
		// Fixture Setup
		Hours novahora = Hours.hours(3);
		Hours horamenor = Hours.hours(1);
		
		// Exercise SUT
		novahora = novahora.minus(2);
		
		// Result Verification
		assertEquals(horamenor,novahora);
	}
	
	@Test
	public void test7_after() {
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,20);
		LocalDate afterData1 = new LocalDate(2017,5,25);
		
		// Exercise SUT
		boolean after = afterData1.isAfter(data1);
		
		// Result Verification
		assertTrue(after);
	}
	
	@Test
	public void test7_before() {
		// Fixture Setup
		LocalDate data1 = new LocalDate(2017,5,20);
		LocalDate beforeData1 = new LocalDate(2017,5,15);
		
		// Exercise SUT
		boolean before = beforeData1.isBefore(data1);
		
		// Result Verification
		assertTrue(before);
	}
	
	@Test
	public void test8_criarDataHora() {
		// Fixture Setup
		
		// Exercise SUT
		LocalDateTime dataHora = new LocalDateTime(2017,5,20,13,10);
		
		// Result Verification
		assertEquals(2017, dataHora.getYear());
		assertEquals(5, dataHora.getMonthOfYear());
		assertEquals(20, dataHora.getDayOfMonth());
		assertEquals(13, dataHora.getHourOfDay());
		assertEquals(10, dataHora.getMinuteOfHour());
	}
	
	@Test
	public void test9_intervaloDatas() {
		// Fixture Setup
		DateTime data1 = new DateTime(2017,5,15,13,10);
		DateTime data2 = new DateTime(2017,5,25,13,10);
		
		// Exercise SUT
		Interval intervalo = new Interval(data1,data2); 
		
		// Result Verification
		assertEquals(10, intervalo.toDuration().getStandardDays());
	}

	@Test
	public void test10_criarPeriodos() {
		// Fixture Setup
		DateTime data1 = new DateTime(2017,12,25,12,0);
		DateTime data2 = new DateTime(2017,12,31,12,0);
		
		// Exercise SUT
		Period period1 = new Period(data1,data2);
		
		// Result Verification
		assertEquals(6, period1.getDays());
	}
	
	@Test(expected = IllegalFieldValueException.class)
	public void test11_diaNegativo() {
		// Fixture Setup
		
		// Exercise SUT
		LocalDate data1 = new LocalDate(2017,5,-20);
		
		// Result Verification
	}

}
