package park.tt.com.parking;

import android.app.Application;

import com.floyd.bean.Bean;
import com.floyd.bean.BeanFactory;
import com.floyd.bean.DefaultBeanCustomer;
import park.tt.com.parking.ui.TestImpl;

import park.tt.com.parking.ui.MainActivity;

/**
 * Created by floyd on 15-7-14.
 */
public class ParkApplication extends Application {
    public void onCreate() {
        super.onCreate();

        BeanFactory.setCustomBean(new DefaultBeanCustomer() {
            @Override
            public Bean createBean(String beanName) {
                if (MainActivity.TEST_BEAN.equals(beanName)) {
                    return new TestImpl();
                }
                return null;
            }
        });
    }
}
