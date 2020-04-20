package foo;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.UnaryOperator;

public class Foo {

    public static void main(String[] args){
        List<String> people = new ArrayList<>();
        people.add("Erik");
        people.add("Anna");
        people.add("Bo");
        people.add("Charlie");
        people.add("Diana");

        //lets say we want 2 filter the list, basted on name length.
        Predicate<String> lengthPred = p -> {
          return p.length() > 2;
        };
        //people.stream().filter(lengthPred).sorted().forEach(System.out::println);   // double colon: we provide a lambda expression
                                                                                    //as argument
        //opgaver!
        //ex1();
        ex2();

    }

    static void ex1(){
        UnaryOperator<String> unaryOperator = s -> {
            StringBuilder sb = new StringBuilder(s);
            return sb.reverse().toString();
        };

        System.out.println(unaryOperator.apply("Time for a break!"));

    }

    //this is bad xD
    static void ex2(){
        List<Student> studentList = new ArrayList<>();
        studentList.add(new Student("Anna", true));
        studentList.add(new Student("Erik", false));
        studentList.add(new Student("Bo", true));

        Predicate<Student> lengthPred = s -> {

            if (s.isActive()){
                return s.isActive();
            }
            else {
                return s.isActive() == false;
            }
        };
        studentList.stream().filter(lengthPred).forEach(System.out::println);
    }

    static void ex4(){
        Function<Student, >
    }
}
