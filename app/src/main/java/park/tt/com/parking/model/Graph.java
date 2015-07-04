package park.tt.com.parking.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by floyd on 15-7-2.
 */
public class Graph {

    static {
        System.loadLibrary("graph");
    }

    private int ref;


    public Graph() {
        init();
    }


    public native void init();


    /**
     * 添加当前点的临近点
     *
     * @param node
     * @param nearNodes
     */
    public native void addVertex(int node, List<Vertex> nearNodes);

    /**
     * 获取最短路径
     *
     * @return
     */
    public native ArrayList<Integer> getShortestPath(int start, int finish);

    /**
     * 清理native环境
     */
    public native void destory();
}
