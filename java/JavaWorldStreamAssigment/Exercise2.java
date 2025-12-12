

import java.util.Comparator;
import java.util.Map;
import java.util.Optional;
import java.util.function.BiConsumer;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.List;



public class Exercise2 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        // get highest city of each continent
		List<City> popularCities = countryDao.getAllContinents().stream().map(
            (continent)->countryDao.findCountriesByContinent(continent).stream()
            .map((country)->country.getCities().stream().max(Comparator.comparingInt(City::getPopulation))) // Maximum Population of Each City
		    .filter(Optional<City>::isPresent).map(Optional<City>::get) // Avoid empties
            .max(Comparator.comparingInt(City::getPopulation))
            
        )
        .filter(Optional<City>::isPresent).map(Optional<City>::get) // Avoid empties
        .collect(Collectors.toList());
        
        System.out.println();
        System.out.println("Popular Cities in Each Continent");
        popularCities.forEach(System.out::println);

    }

}
