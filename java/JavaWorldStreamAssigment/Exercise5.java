



import java.util.Objects;
import java.util.Optional;

import static java.lang.System.out;
import static java.util.stream.Collectors.maxBy;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Exercise5 {

    public static void main(String[] args) {
        CountryDao countryDao = InMemoryWorldDao.getInstance();
        CityDao cityDao = InMemoryWorldDao.getInstance();
       //write your answer here 
        
        City popularCapital = countryDao.findAllCountries().stream() // Country List Stream
        .map((country)->cityDao.findCityById(country.getCapital())) // Capital of Each City
        .filter((x)->x!=null)
        .max(Comparator.comparingInt(City::getPopulation))
        .get(); // limit and collect
       
        System.out.println();
        System.out.println("Most Popular Capital");
        System.out.println(popularCapital);
    }

}