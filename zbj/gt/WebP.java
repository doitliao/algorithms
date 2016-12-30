import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.net.URL;
import java.util.Arrays;
import java.util.List;

public class WebP {
    public static void main(String[] args) {
        String src = "http://static.geetest.com/pictures/gt/579066de6/579066de6.webp";
        src = "579066de6.png";
        try{
          BufferedImage image;
          //image = ImageIO.read(new URL(src));
          image = ImageIO.read(new File(src));
          System.out.println(image);
        }catch(Exception ex){
          ex.printStackTrace();
        }
    }
}
