import org.junit.jupiter.api.Test;

import lombok.extern.
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import java.sql.Connection;
import static org.jdbc.connection.DBConnectionUtil;

@Slf4j
class DBConnectionUtilTest {

    @Test
    void connection() {
      Connection connection = DBConnectionUtil.getConnection()
        assertThan(connection).isNotNull();;
    }
}
