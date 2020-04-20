package foo;

public class Student {

    private String name;
    private boolean active;

    public Student(String name, boolean active) {
        this.name = name;
        this.active = active;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }

    public String toString(){
        return "Student " + getName() + "is acive: " + isActive();
    }
}
