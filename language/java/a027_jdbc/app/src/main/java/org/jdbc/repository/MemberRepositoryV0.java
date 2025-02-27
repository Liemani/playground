package org.jdbc.repository;

import java.util.NoSuchElementException;

import org.jdbc.domain.Member;
import org.jdbc.connection.DBConnectionUtil;
import lombok.extern.slf4j.Slf4j;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.DriverManager;

/**
  * JDBC - DriverManager 사용
  */
@Slf4j
public class MemberRepositoryV0 {
  public Member save(Member member) throws SQLException {
    String query = "insert into member(member_id, money) values (?, ?)";

    Connection connection = null;
    PreparedStatement preparedStatement = null;

    try {
      connection = getConnection();
      preparedStatement = connection.prepareStatement(query);
      preparedStatement.setString(1, member.getMemberId());
      preparedStatement.setInt(2, member.getMoney());
      preparedStatement.executeUpdate();
      return member;
    } catch (SQLException e) {
      log.error("db error", e);
      throw e;
    } finally {
      close(connection, preparedStatement, null);
    }
  }

  public Member findById(String memberId) throws SQLException {
    String query = "select * from member where member_id = ?";

    Connection connection = null;
    PreparedStatement preparedStatement = null;
    ResultSet resultSet = null;

    try {
      connection = getConnection();
      preparedStatement = connection.prepareStatement(query);
      preparedStatement.setString(1, memberId);

      resultSet = preparedStatement.executeQuery();
      if (resultSet.next()) {
        Member member = new Member();
        member.setMemberId(resultSet.getString("member_id"));
        member.setMoney(resultSet.getInt("money"));
        return member;
      } else {
        throw new NoSuchElementException("member not found memberId=" + memberId);
      }
    } catch (SQLException e) {
      log.error("db error", e);
      throw e;
    } finally {
      close(connection, preparedStatement, null);
    }
  }

  public void update(String memberId, int money) throws SQLException {
    String query = "update member set money=? where member_id=?";

    Connection connection = null;
    PreparedStatement preparedStatement = null;

    try {
      connection = getConnection();
      preparedStatement = connection.prepareStatement(query);
      preparedStatement.setInt(1, money);
      preparedStatement.setString(2, memberId);
      int resultSize = preparedStatement.executeUpdate();
      log.info("resultSize = ", resultSize);
    } catch (SQLException e) {
      log.error("db error", e);
      throw e;
    } finally {
      close(connection, preparedStatement, null);
    }
  }

  public void delete(String memberId) throws SQLException {
    String query = "delete from member where member_id=?";

    Connection connection = null;
    PreparedStatement preparedStatement = null;

    try {
      connection = getConnection();
      preparedStatement = connection.prepareStatement(query);
      preparedStatement.setString(1, memberId);
    } catch (SQLException e) {
      log.error("db error", e);
      throw e;
    } finally {
      close(connection, preparedStatement, null);
    }
  }

  private void close(Connection connection, Statement statement, ResultSet resultSet) {
    if (statement != null) {
      try {
        statement.close();
      } catch (SQLException e) {
        log.info("error", e);
      }
    }

    if (connection != null) {
      try {
        connection.close();
      } catch (SQLException e) {
        log.info("error", e);
      }
    }

    if (resultSet != null) {
      try {
        resultSet.close();
      } catch (SQLException e) {
        log.info("error", e);
      }
    }
  }

  private Connection getConnection() {
    return DBConnectionUtil.getConnection();
  }
}
