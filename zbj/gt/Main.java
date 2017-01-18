import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.net.URL;
import java.util.Arrays;
import java.util.List;

public class Main {

    /**
     * 合成指定的多张图片到一张图片
     *
     * @param imgSrcList       图片的地址列表
     * @param topLeftPointList 每张小图片的偏移量
     * @param countOfLine      每行的小图片个数
     * @param cutWidth         每张小图片截取的宽度（像素）
     * @param cutHeight        每张小图片截取的高度（像素）
     * @param savePath         合并后图片的保存路径
     * @param subfix           合并后图片的后缀
     * @return 是否合并成功
     */
    public static boolean combineImages(List<String> imgSrcList, List<String[]> topLeftPointList, int countOfLine, int cutWidth, int cutHeight, String savePath, String subfix) {
        if (imgSrcList == null || savePath == null || savePath.trim().length() == 0) return false;
        BufferedImage lastImage = new BufferedImage(cutWidth * countOfLine, cutHeight * ((int) (Math.floor(imgSrcList.size() * 2))), BufferedImage.TYPE_INT_RGB);
        String prevSrc = "";
        BufferedImage prevImage = null;
        try {
            System.out.println(imgSrcList.size());
            for (int i = 0; i < countOfLine * 2; i++) {
                String src = imgSrcList.get(0);
                BufferedImage image;
                if (src.equals(prevSrc)) image = prevImage;
                else {
                    if (src.trim().toLowerCase().startsWith("http"))
                        image = ImageIO.read(new URL(src));
                    else
                        image = ImageIO.read(new File(src));
                    prevSrc = src;
                    prevImage = image;

                }
                if (image == null) continue;
                String[] topLeftPoint = topLeftPointList.get(i);
                int[] pixArray = image.getRGB(0 - Integer.parseInt(topLeftPoint[0].trim()), 0 - Integer.parseInt(topLeftPoint[1].trim()), cutWidth, cutHeight, null, 0, cutWidth);
                int startX = ((i) % countOfLine) * cutWidth;
                int startY = ((i) / countOfLine) * cutHeight;

                lastImage.setRGB(startX, startY, cutWidth, cutHeight, pixArray, 0, cutWidth);
                System.out.println(pixArray);
            }
            File file = new File(savePath);
            return ImageIO.write(lastImage, subfix, file);
        } catch (Exception ex) {
            ex.printStackTrace();
            return false;
        }
    }

    public static void main(String[] args) {
        // write your code here

        List<String> imgSrcList = Arrays.asList("./579066de6.png");


        List<String[]> topLeftPointList = Arrays.asList(new String[]{"-157","-58"},
                new String[]{"-145","-58"},
                new String[]{"-265","-58"},
                new String[]{"-277","-58"},
                new String[]{"-181","-58"},
                new String[]{"-169","-58"},
                new String[]{"-241","-58"},
                new String[]{"-253","-58"},
                new String[]{"-109","-58"},
                new String[]{"-97","-58"},
                new String[]{"-289","-58"},
                new String[]{"-301","-58"},
                new String[]{"-85","-58"},
                new String[]{"-73","-58"},
                new String[]{"-25","-58"},
                new String[]{"-37","-58"},
                new String[]{"-13","-58"},
                new String[]{"-1","-58"},
                new String[]{"-121","-58"},
                new String[]{"-133","-58"},
                new String[]{"-61","-58"},
                new String[]{"-49","-58"},
                new String[]{"-217","-58"},
                new String[]{"-229","-58"},
                new String[]{"-205","-58"},
                new String[]{"-193","-58"},
                new String[]{"-145","0"},
                new String[]{"-157","0"},
                new String[]{"-277","0"},
                new String[]{"-265","0"},
                new String[]{"-169","0"},
                new String[]{"-181","0"},
                new String[]{"-253","0"},
                new String[]{"-241","0"},
                new String[]{"-97","0"},
                new String[]{"-109","0"},
                new String[]{"-301","0"},
                new String[]{"-289","0"},
                new String[]{"-73","0"},
                new String[]{"-85","0"},
                new String[]{"-37","0"},
                new String[]{"-25","0"},
                new String[]{"-1","0"},
                new String[]{"-13","0"},
                new String[]{"-133","0"},
                new String[]{"-121","0"},
                new String[]{"-49","0"},
                new String[]{"-61","0"},
                new String[]{"-229","0"},
                new String[]{"-217","0"},
                new String[]{"-193","0"},
                new String[]{"-205","0"});
        int countOfLine = 26;
        int cutWidth = 10;
        int cutHeight = 58;

        String save_path = "doitliao.jpg";
        String suffix = "jpg";

        System.out.println(combineImages(imgSrcList,topLeftPointList, countOfLine, cutWidth, cutHeight, save_path, suffix));
    }
}
