# CLAUDE.md

이 문서는 Claude(에이전트)가 이 저장소에서 작업할 때 따라야 할 규칙을 정리한다.

## 프로젝트 개요

콘솔 애플리케이션에서 Model / View / Controller 역할을 명확히 분리한 최소 골격(Skeleton)을 만드는
PoC(Proof of Concept)다. Main 프로젝트인
[`SampleOrderSystem-MINGOO-21015010`](https://github.com/kangtop729/SampleOrderSystem-MINGOO-21015010)의
"MVC 역할 분리 구조" 기술 검증용 참고 산출물이며, 반도체 시료 도메인 로직은 다루지 않는다.
세부 계획은 [`PLAN.md`](PLAN.md) 참고.

## 기술 스택

- 언어: C++
- 빌드: Visual Studio / MSBuild (`.vcxproj`)
- 플랫폼: Win32, x64 / Debug, Release
- 테스트: GoogleTest / GoogleMock (NuGet 패키지)

## 빌드 및 테스트 명령

```
msbuild ConsoleMVC-MINGOO-21015010.vcxproj /p:Configuration=Debug /p:Platform=x64
```

테스트 프로젝트가 구성되면 별도 테스트 실행 파일을 빌드 후 실행한다. (테스트 프로젝트 추가 시 본 절 갱신)

## 작업 원칙

1. **역할 분리(MVC)**: `Model`은 View/Controller를 몰라야 하고, `View`는 콘솔 입출력만 담당하며,
   `Controller`가 흐름을 제어한다. Model/View/Controller 간 순환 의존을 만들지 않는다.
2. **DI 가능한 구조**: View는 Mock으로 교체 가능해야 하며, Controller 테스트 시 Mock View를 주입한다.
3. **가벼운 TDD**: 이 저장소는 PoC이므로 Main만큼 촘촘한 경계값 테스트를 요구하지 않는다. 핵심 동작
   1~2개(정상 입력 시 라우팅, 잘못된 입력 시 처리 등)에 대해 실패하는 테스트를 먼저 작성하고 확인한 뒤,
   최소 구현으로 통과시키는 Red-Green 사이클을 따른다.
4. **작은 단위 커밋**: Phase 단위 혹은 그보다 작은, 의미 있는 단위로 커밋한다. 매 커밋 후에는 사용자의
   검토를 기다리고, 이어서 다음 단계로 넘어가기 전에 확인을 받는다.
5. **커밋 메시지 규칙**: 제목은 반드시 아래 5개 prefix 중 하나로 시작한다.
   - `[feature]` 새 기능 추가
   - `[refactor]` 동작 변경 없는 구조 개선
   - `[fix]` 버그 수정
   - `[docs]` 문서 변경
   - `[test]` 테스트 추가/수정, 테스트 인프라 변경
6. **Clean Code**: 함수는 한 가지 일만 하도록 작게 유지하고, 매직 넘버 대신 의미 있는 이름의 상수를 사용하며,
   불필요한 주석 대신 좋은 이름으로 의도를 드러낸다. 다만 PoC 특성상 Main만큼 세세한 리팩토링/리뷰까지는
   요구하지 않는다.
7. **불필요한 추상화 금지**: 명세에 없는 기능을 미리 만들지 않는다. 메뉴는 최소 골격 수준으로 유지한다.
