package org.jdbc.connection;

import lombok.extern.slf4j.Slf4j;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.DriverManager;

import static org.jdbc.connection.ConnectionConst.*;


@Slf4j
public class DBConnectionUtil {
  public static Connection getConnection() {
    try {
      Connection connection = DriverManagr.getConnection(URL, USERNAME, PASSWORD);
      log.info("get connection={}, class={}", connection, connection.getClass());
      return connection;
    } catch (SQLException e) {
      throw new IllegalStateException(e);
    }
  }
}
