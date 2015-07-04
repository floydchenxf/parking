package park.tt.com.parking.ui;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

import java.util.Arrays;
import java.util.List;

import park.tt.com.parking.R;
import park.tt.com.parking.model.Graph;
import park.tt.com.parking.model.Vertex;


public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Graph a = new Graph();
        a.addVertex(1, Arrays.asList(new Vertex(2, 3), new Vertex(3,4), new Vertex(5,2)));
        a.addVertex(2, Arrays.asList(new Vertex(1, 3), new Vertex(4,1)));
        a.addVertex(3, Arrays.asList(new Vertex(2, 1), new Vertex(4,2)));
        a.addVertex(4, Arrays.asList(new Vertex(3, 2), new Vertex(5,5)));
        a.addVertex(5, Arrays.asList(new Vertex(4, 5), new Vertex(1, 2)));
        List<Integer> t = a.getShortestPath(1,4);
        if (t !=null) {
            for(Integer i: t) {
                Log.e("test", "-----"+i);
            }
        }

        a.destory();

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
}
