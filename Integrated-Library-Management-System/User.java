public class User
{
  private String name;
  private String Surname;
  private int age;
  private boolean active;
  
  public User(String name, String Surname, int age)
  {
    this.name = name;
    this.surname = surname;
    this.age = age;
    active = true;
  }
  
  public String getUserName(){return name;}
  public String getUserSurname(){return surname;}
  public int getUserAge(){return age;}
  public boolean getUserActive(){return active;}
  public String getDetails(){return name + " " + surname + ", " + age + " - " + "Active: " + active;}
}
