# ConsoleMVC-MINGOO-21015010

콘솔 애플리케이션에서 Model / View / Controller 역할을 명확히 분리한 최소 골격(Skeleton) PoC.

Main 프로젝트 [`SampleOrderSystem-MINGOO-21015010`](https://github.com/kangtop729/SampleOrderSystem-MINGOO-21015010)의
"MVC 역할 분리 구조" 기술 요소를 검증하기 위한 참고용 산출물이다.

## 목적

- "메뉴 입력 → 처리 → 화면 출력"이라는 흐름을 Model/View/Controller로 분리한 구조를 검증한다.
- View를 Mock으로 교체해도 Controller를 테스트할 수 있는 DI 가능한 구조를 실험한다.

## 구조

```
ConsoleMVC-MINGOO-21015010/
├── src/
│   ├── Model/
│   │   └── AppState.h/.cpp        # 현재 메뉴 상태, 실행 종료 플래그
│   ├── View/
│   │   ├── IView.h                 # Mock 교체를 위한 View 인터페이스
│   │   └── ConsoleView.h/.cpp      # istream/ostream을 주입받는 콘솔 입출력 구현
│   ├── Controller/
│   │   └── MainController.h/.cpp   # 입력값 라우팅, Model 갱신, View 렌더링 위임
│   └── main.cpp                    # 진입점 (Model/View/Controller 조립)
├── test/                            # gmock 기반 단위 테스트 (Debug 빌드에 포함)
├── CLAUDE.md                        # 에이전트 작업 규칙
├── PLAN.md                          # 구현 계획
└── README.md
```

자세한 구현 계획은 [`PLAN.md`](PLAN.md) 참고.

## 빌드 및 실행

별도 테스트 프로젝트 없이 하나의 `.vcxproj`에서 Debug/Release 두 Configuration만 사용한다.
Debug로 빌드하면 실행 파일 자체가 gmock 테스트 러너가 되고, Release로 빌드해야 실제 콘솔 앱이 뜬다.

```
# 테스트 빌드 및 실행 (Debug 빌드 = 테스트 실행)
msbuild ConsoleMVC-MINGOO-21015010.vcxproj /p:Configuration=Debug /p:Platform=x64
x64\Debug\ConsoleMVC-MINGOO-21015010.exe

# 실제 콘솔 앱 빌드/실행
msbuild ConsoleMVC-MINGOO-21015010.vcxproj /p:Configuration=Release /p:Platform=x64
x64\Release\ConsoleMVC-MINGOO-21015010.exe
```

콘솔 앱은 메뉴(`1. Start`, `0. Exit`)를 출력하고 번호를 입력받아, `0`을 입력할 때까지 반복한다.

## 테스트

- `AppStateTest`: 초기 상태, 종료 플래그, 메뉴 상태 전환 (3개)
- `ConsoleViewTest`: 메뉴 출력, 입력 읽기, 메시지 출력 — 실제 콘솔 대신 `istringstream`/`ostringstream` 주입 (3개)
- `MainControllerTest`: `MockView`(gmock)를 주입해 정상 입력/종료 입력/잘못된 입력 라우팅 검증 (3개)

모든 클래스는 Red(실패하는 테스트 작성) → Green(최소 구현) 순서로 TDD 사이클을 거쳐 구현했다.
