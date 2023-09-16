/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package contactappproject;

import com.sun.jdi.connect.spi.Connection;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.sql.DriverManager;

/**
 *
 * @author satyam nema
 */
class MyConnection {
    public static Connection getConnection(){
        Connection con = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3307/contactapp", "root", "0000");
        } catch (Exception ex) {
           System.out.println(ex.getMessage());
        }
        return con;
        
    }
    
}
