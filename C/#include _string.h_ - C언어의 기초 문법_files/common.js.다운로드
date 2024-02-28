/* 
본 파일은 익명함수에 포함되면 안되기 때문에 컴파일 할 때 익명함수로 감싸지 않도록 해야 한다.
일반적인 컴파일러에서는 bare 옵션을 사용해야 한다.
*/
var ABNORMAL_MESSAGE, BeforeUnloader, BeforeunloadManager, CacheManager, ConfirmDialog, ConfirmDialogManager, Curtain, DOMLoader, Dialog, DiffDialog, DiffDialogManager, InfoDialog, InfoDialogManager, LayerManager, LoginDialog, LoginDialogManager, Menu, Message, MessageManager, NORMAL_MESSAGE, PROCESSINDICATOR_LARGE, PROCESSINDICATOR_SMALL, PROCESSINDICATOR_TINY, ProcessIndicator, Sync, SyncCore, getCookie, htmlspecialchars, number_format, xalert, xconfirm;

$.ajaxSetup({
  'cache': false
});

RegExp.escape = function(value) {
  return value.replace(/[\-\[\]{}()*+?.,\\\^$|#\s]/g, "\\$&");
};

htmlspecialchars = function(str) {
  var div, text;
  text = document.createTextNode(str);
  div = document.createElement('div');
  div.appendChild(text);
  return div.innerHTML;
};

number_format = function(number, decimals, dec_point, thousands_sep) {

  number = (number + '')
    .replace(/[^0-9+\-Ee.]/g, '');
  var n = !isFinite(+number) ? 0 : +number,
    prec = !isFinite(+decimals) ? 0 : Math.abs(decimals),
    sep = (typeof thousands_sep === 'undefined') ? ',' : thousands_sep,
    dec = (typeof dec_point === 'undefined') ? '.' : dec_point,
    s = '',
    toFixedFix = function (n, prec) {
      var k = Math.pow(10, prec);
      return '' + (Math.round(n * k) / k)
        .toFixed(prec);
    };
  // Fix for IE parseFloat(0.55).toFixed(0) = 0;
  s = (prec ? toFixedFix(n, prec) : '' + Math.round(n))
    .split('.');
  if (s[0].length > 3) {
    s[0] = s[0].replace(/\B(?=(?:\d{3})+(?!\d))/g, sep);
  }
  if ((s[1] || '')
    .length < prec) {
    s[1] = s[1] || '';
    s[1] += new Array(prec - s[1].length + 1)
      .join('0');
  }
  return s.join(dec);
};

DOMLoader = (function() {
  class DOMLoader {
    static register(callback) {
      if ($.isReady) {
        return callback();
      } else {
        return this.callbacks.push(callback);
      }
    }

  };

  DOMLoader.callbacks = [];

  return DOMLoader;

}).call(this);

Menu = (function() {
  class Menu {
    constructor(node, dom) {
      this.node = node;
      this.dom = dom;
    }

    show() {
      return this.dom.show();
    }

    hide() {
      this.dom.hide();
      return this.node.removeClass('selected');
    }

  };

  Menu.prototype.node = void 0;

  Menu.prototype.dom = void 0;

  return Menu;

}).call(this);

Curtain = (function() {
  // Curtain 클래스
  class Curtain {
    constructor(selector) {
      this.standard = $(selector);
      this.curtain = $('<div class="curtain static"></div>').hide();
      $(window).resize(() => {
        if (this.curtain.is(':visible')) {
          return this.resize();
        }
      });
    }

    resize() {
      return this.curtain.width($(document).width()).height($(document).height()).css('z-index', this.standard.css('z-index') - 1);
    }

    destatic() {
      return this.curtain.removeClass('static');
    }

    transparent() {
      return this.curtain.css('opacity', 0);
    }

    append(selector = 'body') {
      return this.parent = selector;
    }

    show() {
      this.curtain.appendTo(this.parent).show();
      return this.resize();
    }

    hide() {
      return this.curtain.hide().detach();
    }

    status() {
      if (this.curtain.is(':visible')) {
        return 'visible';
      } else {
        return 'hidden';
      }
    }

  };

  Curtain.prototype.curtain = void 0;

  Curtain.prototype.standard = void 0;

  Curtain.prototype.parent = 'body';

  return Curtain;

}).call(this);

// Process indicator 클래스
PROCESSINDICATOR_TINY = {
  lines: 7,
  length: 2,
  width: 2,
  radius: 3
};

PROCESSINDICATOR_SMALL = {
  lines: 8,
  length: 4,
  width: 3,
  radius: 5
};

PROCESSINDICATOR_LARGE = {
  lines: 10,
  length: 8,
  width: 4,
  radius: 8
};

ProcessIndicator = (function() {
  class ProcessIndicator {
    constructor(container, opt = {}, color = '#000') {
      if (opt['lines'] != null) {
        this.opts.lines = opt.lines;
      }
      if (opt['radius'] != null) {
        this.opts.radius = opt.radius;
      }
      if (opt['width'] != null) {
        this.opts.width = opt.width;
      }
      if (opt['length'] != null) {
        this.opts.length = opt.length;
      }
      this.opts.color = color;
      DOMLoader.register(() => {
        this.spinner = new Spinner(this.opts).spin($(container).get(0));
        return $(this.spinner.el).hide();
      });
    }

    start() {
      return $(this.spinner.el).show();
    }

    stop() {
      return $(this.spinner.el).hide();
    }

  };

  ProcessIndicator.prototype.spinner = void 0;

  ProcessIndicator.prototype.opts = {
    lines: 13,
    length: 7,
    width: 4,
    radius: 10,
    corners: 1,
    rotate: 0,
    color: '#000',
    speed: 1,
    trail: 60,
    shadow: false,
    hwaccel: false,
    className: 'spinner',
    zIndex: 20,
    top: 'auto',
    left: 'auto'
  };

  return ProcessIndicator;

}).call(this);

CacheManager = (function() {
  //spinner.stop();
  class CacheManager {
    static get(key) {
      if (this.buffers[key]) {
        return this.buffers[key];
      } else {
        return null;
      }
    }

    static set(key, value) {
      return this.buffers[key] = value;
    }

  };

  CacheManager.buffers = {};

  return CacheManager;

}).call(this);

LayerManager = (function() {
  class LayerManager {
    static register(target, selector) {
      this.targets.push(target);
      if ($.isReady) {
        target.dom.addClass('registered_layer');
      } else {
        $(() => {
          return target.dom.addClass('registered_layer');
        });
      }
      $(document).on('click touchend', 'body', (event) => {
        if ($('.black-dialog:visible').size() === 0) {
          if (!$(event.target).hasClass('registered_layer') && $(event.target).parents('.registered_layer').size() === 0) {
            return target.hide();
          }
        }
      });
      return $(document).on('click', selector, function() {});
    }

    // must be blank
    static reset() {
      return $.each(this.targets, function(index, target) {
        if (target.dom.is(':visible')) {
          return target.hide();
        }
      });
    }

  };

  LayerManager.targets = [];

  return LayerManager;

}).call(this);

$(document).on('keydown', 'body', function(event) {
  if (event.which === 27) { // esc
    return LayerManager.reset();
  }
});

NORMAL_MESSAGE = 1;

ABNORMAL_MESSAGE = 2;

Message = (function() {
  class Message {
    constructor(text, type1 = 1) {
      this.type = type1;
      switch (this.type) {
        case 1:
          this.container = $('<div class="message"><span class="text"></span></div>');
          break;
        case 2:
          this.container = $('<div class="message"><span class="text"></span><span class="close">닫기</span></div>');
          this.container.find('span.close').click(() => {
            return this.hide();
          });
          this.autohide = 0;
      }
      this.container.hide();
      this.container.hover((function() {
        return $(this).find('span.close').fadeIn();
      }), (function() {
        return $(this).find('span.close').fadeOut();
      }));
      this.container.find('span.text').html(text);
    }

    show() {
      this.container[this.effect.show]();
      if (this.autohide > 0) {
        return setTimeout((() => {
          return this.hide();
        }), this.autohide);
      }
    }

    hide() {
      return this.container[this.effect.hide]();
    }

  };

  Message.prototype.container = void 0;

  Message.prototype.autohide = 2500;

  Message.prototype.effect = {
    show: 'fadeIn',
    hide: 'fadeOut'
  };

  return Message;

}).call(this);

MessageManager = (function() {
  //delete this
  class MessageManager {
    static get() {
      return this._instance;
    }

    constructor() {
      DOMLoader.register(() => {
        this.create();
        $.each(this.buffer, (i) => {
          return this.print(this.buffer[i]);
        });
        return this.buffer = [];
      });
    }

    register(m) {
      if ($.isReady) {
        return this.print(m);
      } else {
        return this.buffer.push(m);
      }
    }

    create() {
      return $('<div id="message-area"></div>').appendTo('body');
    }

    print(m) {
      m.container.appendTo('#message-area');
      return m.show();
    }

  };

  MessageManager._instance = new MessageManager();

  MessageManager.prototype.buffer = [];

  return MessageManager;

}).call(this);

Dialog = class Dialog {
  constructor() {
    this.callback = void 0;
    this.curtain = void 0;
    this.need_stage = true;
    this.dom = $(`<div class="black-dialog">
	<div class="pin"></div>
	<div class="title"></div>
	<div class="content"></div>
	<div class="btns"></div>
</div>`);
  }

  show(callback1, text, opt) {
    var left, stage, top;
    this.callback = callback1;
    if (!$.isPlainObject(opt)) {
      opt = {};
    }
    if (opt.modal !== true && opt.modal !== false) {
      opt.modal = false;
    }
    if (!$.isNumeric(opt.zIndex)) {
      opt.zIndex = 10000;
    }
    if (!$.isNumeric(opt.width || opt.width < 0)) {
      opt.width = 300;
    }
    if (!$.isNumeric(opt.height || opt.height < 0)) {
      opt.height = 'auto';
    }
    if (opt.pinned != null) {
      this.pin;
    } else {
      this.unpin;
    }
    if (opt.id != null) {
      this.dom.attr('id', opt.id);
    }
    if (this.need_stage === true) {
      if ($.type(opt.stage) !== 'object') {
        opt.stage = $('body');
      }
      this.dom.appendTo(opt.stage);
      this.dom.show().find('div.content').html(text.replace(/\\n/g, '<br>'));
      stage = opt.stage;
      if (stage.selector === 'body') {
        top = $(window).scrollTop() + Math.ceil(($(window).height() - this.dom.height()) / 2);
        left = $(window).scrollLeft() + Math.ceil(($(window).width() - opt.width) / 2);
      } else {
        top = Math.ceil((stage.height() - this.dom.height()) / 2);
        left = Math.ceil((stage.width() - opt.width) / 2);
      }
      this.dom.css({
        'width': opt.width + 'px',
        'top': top + 'px',
        'left': left + 'px',
        'z-index': opt.zIndex
      });
    } else {
      this.dom.show().find('div.content').html(text.replace(/\\n/g, '<br>'));
      this.dom.css({
        'width': opt.width + 'px',
        'z-index': opt.zIndex
      });
    }
    if (opt.modal) {
      if (!this.curtain) {
        this.curtain = new Curtain(this.dom);
      }
      if (stage.selector !== 'body') {
        this.curtain.append(stage);
      }
      this.curtain.curtain.css({
        'width': stage.width() + 'px',
        'height': stage.height() + 'px',
        'z-index': opt.zIndex - 1
      });
      return this.curtain.show();
    }
  }

  hide() {
    if ($.isFunction(this.callback)) {
      this.callback(this.dom);
    }
    if ((this.curtain.status()) === 'visible') {
      this.curtain.hide();
    }
    this.dom.removeAttr('id');
    return this.dom.hide().detach().find('div.content').html('');
  }

  unstage() {
    return this.need_stage = false;
  }

  pin() {
    return this.dom.addClass('pinned');
  }

  unpin() {
    return this.dom.removeClass('pinned');
  }

  selector() {
    return this.dom.selector;
  }

  whitify() {
    return this.dom.removeClass('black-dialog').addClass('white-dialog');
  }

};

BeforeUnloader = (function() {
  class BeforeUnloader {
    register(editor, msg) {
      return this.data.push({
        editor: editor,
        msg: msg
      });
    }

  };

  BeforeUnloader.prototype.data = [];

  return BeforeUnloader;

}).call(this);

BeforeunloadManager = (function() {
  class BeforeunloadManager {
    static get() {
      return this._instance;
    }

  };

  BeforeunloadManager._instance = new BeforeUnloader();

  return BeforeunloadManager;

}).call(this);

$(window).on('beforeunload', function(event) {
  var datum, editor, j, len, manager, msg, ref;
  manager = BeforeunloadManager.get();
  ref = manager.data;
  for (j = 0, len = ref.length; j < len; j++) {
    datum = ref[j];
    editor = datum.editor;
    msg = datum.msg;
    if (editor.changed) {
      event = event || window.event;
      if (event) {
        //For IE and Firefox prior to version 4
        event.returnValue = msg;
      }
      // For Safari
      return msg;
    }
  }
});

LoginDialog = (function() {
  // Login 관련 클래스
  class LoginDialog {
    constructor(selector) {
      this.selector = selector;
      if ($.isReady) {
        this.dom = $(selector);
        this.curtain = new Curtain(this.dom);
      } else {
        DOMLoader.register(() => {
          this.dom = $(selector);
          return this.curtain = new Curtain(this.dom);
        });
      }
      $(document).on('submit', selector, () => {
        this.try();
        return false;
      });
      $(document).on('click', `${selector} button.btn_close`, () => {
        this.hide();
        return false;
      });
      $(document).on('keydown', 'form#login-static', function(event) {
        if (event.which === 13) {
          return $(selector).trigger('submit');
        }
      });
    }

    try() {
      if ($(this.selector).hasClass('super_password')) {
        this.ajax_url = 'auth/super_login_ajax';
      }
      $.ajax({
        url: base_url + this.ajax_url,
        data: {
          email: $('#predialog_email').val(),
          password: $('#predialog_password').val(),
          rememberme: $('#rememberme:checked').size() ? 'on' : 'off'
        },
        dataType: 'json',
        success: (response) => {
          if (response.result === true) {
            if ($.isFunction(this.callback)) {
              this.callback(response);
              this.curtain.hide();
              this.dom.removeData(['callback', 'curtain']);
            }
            return location.reload();
          } else {
            return xalert(null, response.msg, {
              modal: true
            });
          }
        },
        type: 'post'
      });
      return false;
    }

    show(standalone = false) {
      return location.href = base_url + 'auth?returnURL=' + encodeURI(location.href);
    }

    /*if @dom.is ':hidden'
    if standalone
    	do @dom.appendTo('body').addClass('alone').show

    	@dom.css
    		'left': (Math.ceil (do $(window).width - do @dom.width) / 2) + 'px'
    		'top': (Math.ceil (do $(window).height - do @dom.height) / 2) + 'px'

    	do @curtain.show
    else
    	@dom.parent().addClass 'selected'
    	do @dom.show

    do @dom.find('input[name=email]').focus*/
    hide() {
      var ref;
      ((ref = this.curtain.hide()) != null ? ref.remove : void 0)();
      this.dom.removeClass('alone').removeAttr('style').appendTo('#login');
      return this.dom.parent().removeClass('selected');
    }

    getSelector() {
      return this.selector;
    }

  };

  LoginDialog.prototype.curtain = void 0;

  LoginDialog.prototype.callback = void 0;

  LoginDialog.prototype.dom = void 0;

  LoginDialog.prototype.selector = void 0;

  LoginDialog.prototype.ajax_url = 'auth/login_ajax';

  return LoginDialog;

}).call(this);

LoginDialogManager = (function() {
  class LoginDialogManager {
    static get() {
      return this._instance;
    }

  };

  LoginDialogManager._instance = new LoginDialog('#login-static');

  return LoginDialogManager;

}).call(this);

// Info dialog 클래스
InfoDialog = class InfoDialog extends Dialog {
  constructor() {
    super();
    $('div.btns', this.dom).append('<button class="close">닫기</button>');
    $('div.btns button.close', this.dom).click(() => {
      return this.hide();
    });
  }

  hide() {
    return super.hide(true);
  }

};

InfoDialogManager = (function() {
  class InfoDialogManager {
    static get() {
      return this._instance;
    }

  };

  InfoDialogManager._instance = new InfoDialog();

  return InfoDialogManager;

}).call(this);

ConfirmDialog = (function() {
  class ConfirmDialog extends Dialog {
    constructor() {
      super();
      $('div.btns', this.dom).append('<button class="positive"></button><button class="negative"></button>');
      $('div.btns button.positive', this.dom).click(() => {
        return this.hide(true);
      });
      $('div.btns button.negative', this.dom).click(() => {
        return this.hide();
      });
    }

    show(callback1, neg_callback, text, opt) {
      this.callback = callback1;
      this.neg_callback = neg_callback;
      super.show(this.callback, text, opt != null ? opt : opt = {});
      if (!$.isPlainObject(opt != null ? opt.label : void 0)) {
        opt.label = {
          positive: '확인',
          negative: '취소'
        };
      }
      $('div.btns button.positive', this.dom).text(opt.label.positive);
      return $('div.btns button.negative', this.dom).text(opt.label.negative);
    }

    hide(active = false) {
      if (active) {
        if ($.isFunction(this.callback)) {
          this.callback(this.dom);
        }
      } else {
        if ($.isFunction(this.neg_callback)) {
          this.neg_callback(this.dom);
        }
      }
      if ((this.curtain != null) && (this.curtain.status() === 'visible')) {
        this.curtain.hide();
      }
      this.dom.removeAttr('id');
      return this.dom.hide().detach().find('div.content').html('');
    }

  };

  ConfirmDialog.prototype.neg_callback = void 0;

  return ConfirmDialog;

}).call(this);

ConfirmDialogManager = (function() {
  class ConfirmDialogManager {
    static get() {
      return this._instance;
    }

  };

  ConfirmDialogManager._instance = new ConfirmDialog();

  return ConfirmDialogManager;

}).call(this);

DiffDialog = (function() {
  class DiffDialog {
    constructor(selector) {
      this.selector = selector;
      this.dom = $(selector);
      $(document).on('submit', selector, () => {
        this.try();
        return false;
      });
      $(document).on('click', `${selector} button.btn_submit`, (target) => {
        this.hide();
        $('#form div.btns input#save_force', opener.window.document).val(1);
        $('#form button#save', opener.window.document).trigger('click');
        return false;
      });
    }

    show(meta, diff) {
      this.meta = meta;
      $('div.body div.wrapper', this.selector).html(diff);
      return $('div.tail p.explain', this.selector).html(`<span class=\"user\">${this.meta.other}</span> 님이 다른 곳에서 <time>${this.meta.time}</time>에 이 문서를 수정하셨습니다. 이 문서를 지금 사용자께서 작성중인 문서와 비교, 선택하여 충돌을 해결하신 후 '충돌해결' 버튼을 눌러주세요. 자세한 내용은 <a href=\"${base_url}module/180/4523\" target=\"_blank\">도움말</a>을 참고하시기 바랍니다.`);
    }

    hide() {
      return window.close();
    }

    getSelector() {
      return this.selector;
    }

  };

  DiffDialog.prototype.meta = void 0;

  DiffDialog.prototype.callback = void 0;

  DiffDialog.prototype.dom = void 0;

  DiffDialog.prototype.selector = void 0;

  return DiffDialog;

}).call(this);

DiffDialogManager = (function() {
  class DiffDialogManager {
    static get() {
      return this._instance;
    }

  };

  DiffDialogManager._instance = new DiffDialog("#diff_dialog");

  return DiffDialogManager;

}).call(this);

Sync = (function() {
  class Sync {
    static get() {
      return this._instance != null ? this._instance : this._instance = new SyncCore();
    }

    static add(type, action) {
      var obj;
      obj = this.get();
      return obj.add(type, action);
    }

    static fire(type, value) {
      var obj;
      obj = this.get();
      return obj.fire(type, value);
    }

  };

  Sync._instance = void 0;

  return Sync;

}).call(this);

SyncCore = (function() {
  class SyncCore {
    add(type, action) {
      var base;
      if ((base = this.event)[type] == null) {
        base[type] = [];
      }
      return this.event[type].push(action);
    }

    fire(type, value) {
      var action, j, len, ref, results;
      if (this.event.hasOwnProperty(type)) {
        ref = this.event[type];
        results = [];
        for (j = 0, len = ref.length; j < len; j++) {
          action = ref[j];
          if (typeof action.sync === 'function') {
            results.push(action.sync(value));
          } else if (type === 'x' && typeof action.syncX === 'function') {
            results.push(action.syncX(value));
          } else if (type === 'y' && typeof action.syncY === 'function') {
            results.push(action.syncY(value));
          } else {
            results.push(action(value));
          }
        }
        return results;
      }
    }

  };

  SyncCore.prototype.event = {};

  return SyncCore;

}).call(this);

//=========================================================================================================
xalert = function(callback, text, option) {
  var dialog;
  dialog = InfoDialogManager.get();
  return dialog.show(callback, text, option);
};

// 레거시 용.
xconfirm = function(ycallback, ncallback, text, option) {
  var dialog;
  dialog = ConfirmDialogManager.get();
  return dialog.show(ycallback, ncallback, text, option);
};

(function($) {
  var start;
  $(document).on('click', 'input[type="button"].link', function(event) {
    return location.href = $(event.target).attr('href');
  });
  $(document).on('click', 'body.draggable a', function() {
    return false;
  });
  $(document).on('scroll touchmove', '.curtain.static, .black-dialog.static', function(event) {
    event.preventDefault();
    return event.stopPropagation();
  });
  start = 0;
  $(document).on('scroll touchstart', '.scrollbox', function(event) {
    return start = event.originalEvent.pageY;
  });
  $(document).on('scroll touchmove', '.scrollbox', function(event) {
    var child, current, parent;
    current = event.originalEvent.pageY;
    parent = $(event.currentTarget);
    child = parent.find('> div.wrapper, > ul');
    if (start > current) {
      if (parent.height() + parent.scrollTop() >= child.height()) {
        event.stopPropagation();
        return event.preventDefault();
      }
    }
  });
  //else if start > current
  return $(document).on('click', '#attention', function(event) {
    return $(event.currentTarget).hide();
  });
})(jQuery);

getCookie = function(cname) {
  var c, ca, i, name;
  name = cname + '=';
  ca = document.cookie.split(';');
  i = 0;
  while (i < ca.length) {
    c = ca[i];
    while (c.charAt(0) === ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) === 0) {
      return c.substring(name.length, c.length);
    }
    i++;
  }
  return '';
};
