

import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;




public class Exercise1 {

   public static void main(String[] args) {
	   // get highest population city for each country
      CountryDao countryDao= InMemoryWorldDao.getInstance();
      List<City> popularCities = countryDao.findAllCountries().stream() // Country List Stream
		  .map((country)->country.getCities().stream().max(Comparator.comparingInt(City::getPopulation))) // Maximum Population of Each City
		  .filter(Optional<City>::isPresent).map(Optional<City>::get) // Avoid empties
		  .limit(10).collect(Collectors.toList()); // limit and collect
	   
	  System.out.println();
	  System.out.println("Popular Cities in Each Country");
	  popularCities.forEach(System.out::println); // print output
   }

}