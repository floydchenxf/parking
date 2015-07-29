package park.tt.com.parking;

import android.app.Application;

import com.floyd.bean.Bean;
import com.floyd.bean.BeanFactory;
import com.floyd.bean.ClassBeanCustomer;
import com.floyd.bean.DefaultBeanCustomer;
import park.tt.com.parking.ui.TestImpl;

import park.tt.com.parking.ui.MainActivity;

/**
 * Created by floyd on 15-7-14.
 */
public class ParkApplication extends Application {
    public void onCreate() {
        super.onCreate();

//        ClassBeanCustomer beanCustomer = new ClassBeanCustomer();
//        beanCustomer.registerBeanClass(MainActivity.TEST_BEAN, TestImpl.class);
//        BeanFactory.setCustomBean(beanCustomer);
    }
}
