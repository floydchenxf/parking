package park.tt.com.parking.ui;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

import com.floyd.bean.BeanFactory;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.Arrays;
import java.util.List;

import park.tt.com.parking.R;
import park.tt.com.parking.model.Graph;
import park.tt.com.parking.model.Vertex;


public class MainActivity extends ActionBarActivity implements TestInterface {

    public static final String TEST_BEAN = "testBean";
    private TestInterface testInterface;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Graph a = new Graph();
        a.addVertex(1, Arrays.asList(new Vertex(2, 1)));
        a.addVertex(2, Arrays.asList(new Vertex(1, 1), new Vertex(3, 1)));
        a.addVertex(3, Arrays.asList(new Vertex(2, 1), new Vertex(4, 1), new Vertex(8, 1)));
        a.addVertex(4, Arrays.asList(new Vertex(5, 1), new Vertex(3, 1)));
        a.addVertex(5, Arrays.asList(new Vertex(4, 1), new Vertex(6, 1)));
        a.addVertex(6, Arrays.asList(new Vertex(5, 1), new Vertex(7, 1)));
        a.addVertex(7, Arrays.asList(new Vertex(10, 1), new Vertex(6, 1), new Vertex(17, 1)));
        a.addVertex(8, Arrays.asList(new Vertex(9, 1), new Vertex(11, 1), new Vertex(12, 1), new Vertex(13, 1), new Vertex(3, 1)));
        a.addVertex(9, Arrays.asList(new Vertex(8, 1), new Vertex(10, 1)));
        a.addVertex(10, Arrays.asList(new Vertex(7, 1), new Vertex(9, 1), new Vertex(15, 1)));
        a.addVertex(11, Arrays.asList(new Vertex(8, 1), new Vertex(18, 1)));
        a.addVertex(12, Arrays.asList(new Vertex(8, 1), new Vertex(19, 1)));
        a.addVertex(13, Arrays.asList(new Vertex(8, 1), new Vertex(14, 1), new Vertex(20, 1)));
        a.addVertex(14, Arrays.asList(new Vertex(13, 1), new Vertex(22, 1)));
        a.addVertex(15, Arrays.asList(new Vertex(10, 1)));
        a.addVertex(16, Arrays.asList(new Vertex(17, 1)));
        a.addVertex(17, Arrays.asList(new Vertex(16, 1), new Vertex(25, 1), new Vertex(7, 1)));
        a.addVertex(18, Arrays.asList(new Vertex(11, 1), new Vertex(19, 1)));
        a.addVertex(19, Arrays.asList(new Vertex(18, 1), new Vertex(20, 1), new Vertex(12, 1)));
        a.addVertex(20, Arrays.asList(new Vertex(19, 1), new Vertex(21, 1), new Vertex(13, 1)));
        a.addVertex(21, Arrays.asList(new Vertex(20, 1)));
        a.addVertex(22, Arrays.asList(new Vertex(14, 1), new Vertex(23, 1), new Vertex(26, 1)));

        a.addVertex(23, Arrays.asList(new Vertex(22, 1), new Vertex(24, 1)));
        a.addVertex(24, Arrays.asList(new Vertex(23, 1), new Vertex(25, 1)));
        a.addVertex(25, Arrays.asList(new Vertex(24, 1), new Vertex(17, 1)));
        a.addVertex(26, Arrays.asList(new Vertex(22, 1)));
        List<Integer> t = a.getShortestPath(15, 26);
        if (t != null) {
            for (Integer i : t) {
                Log.e("test", "-----" + i);
            }
        }

        a.destory();

        BeanFactory.registerBean(TEST_BEAN, this);
        testInterface = BeanFactory.getBean(TEST_BEAN);
        if (testInterface != null) {
//            String kk = null;
//            try {
//                JSONObject o = new JSONObject();
//                o.put("code", 200);
//                o.put("msg", "读取菜单数据成功");
//                JSONObject ee = new JSONObject();
//                ee.put("boughtItems", 1);
//                ee.put("goldenTree", 1);
//                ee.put("salerCenter", 1);
//                ee.put("myTaobao", 1);
//                ee.put("plugins", 1);
//
//                o.put("data", ee);
//                kk = o.toString();
//
//            } catch (JSONException e) {
//                e.printStackTrace();
//            }
            String kk = "\"{\"code\":200,\"msg\":\"读取菜单数据成功\",\"data\":{\"boughtItems\":1,\"goldenTree\":1,\"salerCenter\":1,\"myTaobao\":1,\"plugins\":1}}\"";

            testInterface.callTest(kk);
        }

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        BeanFactory.unRegisterBean(TEST_BEAN);
    }

    @Override
    public void initBean() {
        Log.e("kkk", "-----------initBean");
    }

    @Override
    public void destoryBean() {
        Log.e("kkk", "-----------destoryBean");
    }

    @Override
    public void callTest(String k) {
        Log.e("kkk", k);
    }
}
