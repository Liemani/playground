import lombok.extern.
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import java.sql.Connection;
import static org.jdbc.connection.DBConnectionUtil;

@Slf4j
class MemberRepositoryV0Test {
  MemberRepositoryV0 repository = new MemberRepositoryV0();

  @Test
  void crud() throws SQLException {
    // save
    Member member = new Member("memberV0", 10000);
    repository.save(member);

    // findById
    Member member = repository.findById(member.getMemberId());
    log.info("findMember={}", findMember);

    // update: money: 10000 -> 20000
    repository.updqte(member.getMemberId(), 20000);
    Member updatedMember = repository.findById(member.getMemberId());
    assertThat(updatedMember.getMoney()).isEqualTo(20000);

    // delete
    repository.delete(member.getMemberId());
    Assertions.assertThatThrownBy(() -> repository.findById(member.getMemberId()))
      .isInstanceOf(NoSuchElementException.class);
  }
}
